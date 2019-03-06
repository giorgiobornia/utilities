;;  gimp -i -b '(mycrop "*.png"  new-width new-height offx offy)' -b '(gimp-quit 0)'
;;  new-width 600
;; new-height 840
;; offx 800
;; offy 200


;; seems like this script does not work if you provide an explicit list in 'pattern',
;; other than "*.tif"

(define (mycrop  pattern new-width new-height offx offy)
  (let* ((filelist (cadr (file-glob pattern 1))))
    (while (not (null? filelist))
           (let* ((filename (car filelist))
                  (image (car (gimp-file-load RUN-NONINTERACTIVE filename filename)))
                   (drawable (car (gimp-image-get-active-layer image))))
;;              (plug-in-unsharp-mask RUN-NONINTERACTIVE   drawable radius amount threshold)
             (gimp-image-crop image  new-width new-height offx offy)
             (gimp-file-save RUN-NONINTERACTIVE  image drawable filename filename)
(gimp-message "ciao")
             (gimp-image-delete image))
           (set! filelist (cdr filelist)))))


;;  gimp -i -b '(myscale "*.png"  new-width new-height)' -b '(gimp-quit 0)'
(define (myscale  pattern scale_in)
  (let* ((filelist (cadr (file-glob pattern 1))))
    (while (not (null? filelist))
           (let* ((filename (car filelist))
                  (image (car (gimp-file-load RUN-NONINTERACTIVE filename filename)))
                   (drawable (car (gimp-image-get-active-layer image))))

 (let*
 (;;local variables
     (ScaleFac scale_in)
     (width  (car (gimp-image-width image))) 
     (height (car (gimp-image-height image)))
;; (set! width (car (gimp-image-width image)))
;; (set! height (car (gimp-image-height image)))
 )
 ;;   (gimp-image-scale image (/ width ScaleFac)  (/ height ScaleFac)) 
  (gimp-image-resize image (/ width ScaleFac)  (/ height ScaleFac) 0 0) ;;pseudo-alternative to scale 
    (gimp-message "gira che e' una bellezza")
);;let* local variables
             (gimp-file-save RUN-NONINTERACTIVE image drawable filename filename)
             (gimp-image-delete image)
);;let* ((filename
           (set! filelist (cdr filelist)))
);;(let* ((filelist

)
