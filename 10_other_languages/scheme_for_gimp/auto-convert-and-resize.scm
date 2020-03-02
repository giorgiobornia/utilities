; Studio Tecnico Arch. Giuseppe Conte  
; via Roma, 28
; 72026 - San Pancrazio Salentino (BR) - ITALY
;
; Plugin: auto-convert-and-resize.scm
; Author:  Arch. Giuseppe Conte 
; Date: 14 febbraio 2004
; Revision: 21 novembre 2004
;						13 gennaio  2008 update to TinyScheme
;						14 maggio   2009 update to Gimp 2.6.6
; Version: 4.0
; Last version at: http://xoomer.virgilio.it/lwcon/gimp/
; Help guide at  : http://xoomer.virgilio.it/lwcon/gimp/scripts/auto-convert-and-resize.htm
;
; Description: 
; Read from file *.txt a list of images to resize or cut
; and convert it to other format. 
;
;	Example of imagelist.txt file:
;		"C:/Documenti/immagini/paesaggio.jpg"
;		"C:/Foto/Estate/castello.jpg"
;		"C:/Foto/Matrimonio/Chiesa/scambio_anelli.jpg"
;		"C:/Foto/Matrimonio/Pranzo/taglio_torta.tiff"
;		"C:/Lavoro/Cantiere/Strutture/fondazioni_05.bmp"
;		..
;		..
; -----------------------------------------------------------------------------
;
; License:
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.
; 
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
; 
; You should have received a copy of the GNU General Public License
; along with this program; if not, write to the Free Software
; Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
; -----------------------------------------------------------------------------
;
; Define the function:

(define TYPE-LIST  (list "BMP" "DCM" "FIT" "GBR" "GIF" "GIH" "GTM" "HEADER" "ICO" "Jpeg" "PAT" "PBM" "PCX" "PGM" "PIX" "PNG" "PNM" "PPM" "EPS" "PostScript" "PSD" "RAW" "SGI" "SUNRAS" "TGA" "Tiff" "XBM" "XCF (GIMP)" "Xpm" "XWD" "gzip" "CEL"))


(define (script-fu-auto-convert-and-resize Filename OptionSize Ratio newHeight newWidth save-ext)
	(let* (	(file-stream 0)
					(oggetto "")
					(lung 0)
					(cnt 0)
					(Image 0)
					(drawable 0)
					(owidth 0)
					(oheight 0)
					(scx 1) (scy 1) (sc 1)
					(width 0) (height 0)
					(cwidth 0) (cheight 0)
					(outFile "") (imageTipo 0)
					(newlayer "") (newchannel "")
					(desc "") (spaziatura 0)
					(spacing 0) (colonne 1) (righe 1) (dimensione 1) 
					(rank (make-vector 1 'byte )) 
					(sele '(incremental)) (canaleAlfa 0)
					(activePath "")
					(openFile "")
					(temp "")
				)
;; apre il file in lettura
	(set! activePath (solopath Filename))
	(set! openFile (open-input-file Filename ))
	
	;(while (set! oggetto (read openFile))
	(while (not (eof-object? (set! oggetto (read openFile))))
		(set! lung (string-length oggetto))
		(if (<= lung 1) (begin (set! oggetto (read openFile)) (set! cnt 0)) ())
		(begin
			(set! oggetto (string-trim oggetto))   ;elimina spazi finali ed iniziali
			(set! Image (car (gimp-file-load 1 oggetto oggetto)))
			(set! drawable (car (gimp-image-active-drawable Image)))
			(set! owidth  (car (gimp-image-width  Image)))
			(set! oheight (car (gimp-image-height Image)))

			; imposta il rapporto tra base ed altezza verifica opzioni
			(if (= Ratio TRUE) 
				(begin 
					;;determina il fattore di scala
					(set! scx (/ newWidth owidth))
					(set! scy (/ newHeight oheight))
					(set! sc (if (<= scx scy) scx scy))
					(set! sc (if (>= scx scy) scy scx))
					(set! width (* sc owidth))
					(set! height (* sc oheight))
				);begin vero

				(begin
					(set! width newWidth)
					(set! height newHeight)
				);begin falso 

			); end if

			(cond
				( (= OptionSize 0)   ;original size
					;nessuna operazione
				)
				
				( (= OptionSize 1)   ; scale
	   				(gimp-image-scale Image width height)
				)
				
				( (= OptionSize 2)   ; crop image
					(if (< owidth width) (set! cwidth owidth) (set! cwidth width))
					(if (< oheight height) (set! cheight oheight) (set! cheight height))
	   			(gimp-crop Image cwidth cheight 0 0)
				)

			);cond

			;salva il file in base al formato selezionato che deve essere compatibile con l'immagine sorgente
			(cond
				( (= save-ext 0)   ; BMP
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".bmp"))
					(file-bmp-save 1 Image drawable outFile outFile)
				)
				( (= save-ext 1)   ; DCM
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".dcm"))
					(file-dicom-save 1 Image drawable outFile outFile)
				)
				( (= save-ext 2)   ; FIT
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".fit"))
					(file-fits-save 1 Image drawable outFile outFile)
				)

				( (= save-ext 3)   ; GBR need gray scale or RGBA image
					;(gimp-message "conversione in GBR non implementata") OK funziona
					(set! imageTipo (car (gimp-image-base-type Image)))
					(if (> imageTipo 0)
					 	(begin
						(gimp-image-convert-rgb Image)
						(set! newlayer (car (gimp-layer-new Image owidth oheight RGBA_IMAGE "ATG" 100 NORMAL)))
						(gimp-image-add-layer Image newlayer 0)
						);begin
					);end if
					(set! desc (solonomefile oggetto) )
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".gbr"))
					(set! spaziatura 100)
					(file-gbr-save 1 Image drawable outFile outFile spaziatura desc)
				)

				( (= save-ext 4)   ; GIF
					;(gimp-message "conversione in GIF non implementata")
					(gimp-image-convert-indexed Image FIXED-DITHER MAKE-PALETTE 255 TRUE TRUE "Palette")
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".gif"))
					(file-gif-save 1 Image drawable outFile outFile 0 0 0 0)
				)

				( (= save-ext 5)   ; GIH
					;non funziona problemi con STRINGARRAY ->sostituito stringarray con list e funziona
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".gih"))
					(set! spacing 100)
					(set! colonne 1)
					(set! righe 1)
					(set! dimensione 1)
					(vector-set! rank 0 1) 
					(set! sele '("incremental") )
					(gimp-layer-add-alpha drawable)
					(file-gih-save 1 Image drawable outFile outFile spacing outFile width height colonne righe dimensione rank dimensione sele)
				)

				( (= save-ext 6)   ; GTM
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".gtm"))
					(file-gtm-save 1 Image drawable outFile outFile)
				)

				( (= save-ext 7)   ; HEADER C unsigned character array
					;nessuna operazione OK
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".h"))
					(file-header-save 1 Image drawable outFile outFile)
				)
				
				( (= save-ext 8)   ; ICO
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".ico"))
					(file-ico-save 1 Image drawable outFile outFile )
				)

				( (= save-ext 9)   ; Jpeg
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".jpg"))
					(file-jpeg-save 1 Image drawable outFile outFile 0.2 0 1 0 "Copyright Arch. Giuseppe Conte" 0 1 0 0)
				)

				( (= save-ext 10)   ; PAT
					(set! drawable (car (gimp-image-flatten Image)))
					(set! desc (solonomefile oggetto) )
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".pat"))
					(file-pat-save 1 Image drawable outFile outFile desc )
				)

				( (= save-ext 11)   ; PBM saving handles all image types except those with alpha channels
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".pnm"))
					(file-pbm-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 12)   ; PCX
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".pcx"))
					(file-pcx-save 1 Image drawable outFile outFile)
				)

				( (= save-ext 13)   ; PGM saving handles all image types except those with alpha channels
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".pgm"))
					(file-pgm-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 14)   ; PIX
					(gimp-message "conversione nel formato PIX non implementata")
					;(set! outFile (string-append oggetto "-" (number->string Image 10) ".pix"))
					;(file-pix-save 1 Image drawable outFile outFile)
					;nessuna operazione
				)

				( (= save-ext 15)   ; PNG
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".png"))
					(file-png-save 1 Image drawable outFile outFile FALSE 6 FALSE FALSE FALSE TRUE TRUE)
				)

				( (= save-ext 16)   ; PNM saving handles all image types without transparency
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".pnm"))
					(file-pnm-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 17)   ; PPM saving handles RGB images without transparency.
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".pnm"))
					(file-ppm-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 18)   ; PostScript saving handles all image types except those with alpha channels.
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".eps"))
					(file-eps-save 1 Image drawable outFile outFile 0 0 0 0 1 1 0 1 0 2)
					;nessuna operazione
				)

				( (= save-ext 19)   ; PostScript saving handles all image types except those with alpha channels.
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".ps"))
					(file-ps-save 1 Image drawable outFile outFile 0 0 0 0 1 1 0 0 0 2)
					;nessuna operazione
				)

				( (= save-ext 20)   ; PSD Photoshop format
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".psd"))
					(file-psd-save 1 Image drawable outFile outFile 0 1)
				)

				( (= save-ext 21)   ; RAW
					(gimp-message "conversione nel formato RAW non implementata")
					;(set! outFile (string-append oggetto "-" (number->string Image 10) ".raw"))
					;(file-raw-save 1 Image drawable outFile outFile )
				)

				( (= save-ext 22)   ; SGI
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".sgi"))
					(file-sgi-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 23)   ; SUNRAS saving handles all image types except those with alpha channels
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".im1"))
					(file-sunras-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 24)   ; TGA
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".tga"))
					(file-tga-save 1 Image drawable outFile outFile 0 0)
				)

				( (= save-ext 25)   ; Tiff
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".tif"))
					(file-tiff-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 26)   ; XBM
					;converte prima l'immagine in momocromatico e poi la salva nel formato XBM
					(gimp-image-convert-indexed Image FIXED-DITHER MONO-PALETTE 255 TRUE TRUE "Palette")
					(set! desc (solonomefile oggetto) )
					;estraggo il prefisso dal nome del file
					(set! temp (substring desc 0 (- (string-length desc) 4)))
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".xbm"))
					(file-xbm-save 1 Image drawable outFile outFile "Commento" 0 0 0 temp 0 "msk")
				)
				( (= save-ext 27)   ; XCF GIMP
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".xcf"))
					(gimp-xcf-save 0 Image drawable outFile outFile)
				)

				( (= save-ext 28)   ; XPM Save files in XPM (X11 Pixmap) format
					;nessuna operazione 
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".xpm"))
					(file-xpm-save 1 Image drawable outFile outFile 0)
				)

				( (= save-ext 29)   ; XWD saving handles all image types except those with alpha channels
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".xwd"))
					(file-xwd-save 1 Image drawable outFile outFile)
				)
				
				( (= save-ext 30)   ; Gzip save file compressed with gzip
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".gz"))
					(file-gz-save 1 Image drawable outFile outFile)
				)
				( (= save-ext 31)   ; CEL save files in KISS CEL file format
					(set! desc (solonomefile oggetto) )
					(set! outFile (string-append oggetto "-" (number->string Image 10) ".cel"))
					(file-cel-save 1 Image drawable outFile outFile desc)
				)

			);cond
			
			
		);end begin
		(gimp-displays-flush)
	); end while
   ; chiude il file aperto
	(close-input-port openFile)

	);let
);def

(script-fu-register
	"script-fu-auto-convert-and-resize"
	_"<Toolbox>/Xtns/Script-Fu/_ATG/Auto _convert and resize..."
	"Legge da un file di testo l'elenco delle immagini che si \n desidera convertire automaticamente. Ogni riga del file deve contenere il percorso completo di una sola immagine racchiuso tra virgolette. Le immagini vengono aperte, opzionalmente scalate o ritagliate, e salvate nel formato desiderato nella stessa cartella d'origine."
	"Arch. Giuseppe Conte"
	"Arch. Giuseppe Conte"
	"14 maggio 2009 - Ver. 4.0"
	""
	SF-FILENAME _"List file text" (string-append "" gimp-data-directory "/elenco.txt")
	SF-OPTION "Size " '("Original Size" "Scale" "Crop")
	SF-TOGGLE  "Preserve aspect ratio" TRUE
	SF-ADJUSTMENT "Height" '(110 0 9999 1 1 0 1)
	SF-ADJUSTMENT "Width" '(180 0 9999 1 1 0 1)
	SF-OPTION "Covert to. "  TYPE-LIST
)

;;;;;;;

;;funzioni di servizio
;;; Estrae il solo percorso

(define (solopath x)
	(let* ( (cnt 0)
					(lung 0)
					(fine 0)
				)
	(set! lung (string-length x))
	(while (< cnt lung)
				(if (equal? (substring x cnt (+ cnt 1)) "\\") (set! fine cnt) )
				(set! cnt (+ cnt 1))
	);while
	;(gimp-message (number->string fine))
	(substring x 0 (+ fine 1))
	
	);let

);def

;;restituisce il nome del file senza il percorso

(define (solonomefile x)
	(let* ( (cnt 0)
					(lung 0)
					(fine 0)
				)
	(set! lung (string-length x))
	(while (< cnt lung)
				(if (equal? (substring x cnt (+ cnt 1)) "\\") (set! fine cnt) )
				(set! cnt (+ cnt 1))
	);while
	;(gimp-message (number->string fine))
	(substring x (+ fine 1) lung)
	
	);let

);def


;;fine funzioni di servizio