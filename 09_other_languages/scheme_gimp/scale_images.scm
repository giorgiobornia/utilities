
;;  gimp -i -b '(scale_images "*.png"  new-width new-height)' -b '(gimp-quit 0)'
(define (scale_images  pattern scale_in)
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
