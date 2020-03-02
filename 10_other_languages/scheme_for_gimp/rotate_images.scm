;;  gimp -i -b '(rotate_images "*.tif" 1)' -b '(gimp-quit 0)'

;; rot_index   ROTATE-90 (0), ROTATE-180 (1), ROTATE-270 (2) 

;; seems like this script does not work if you provide an explicit list in 'pattern',
;; other than "*.tif"

(define (rotate_images  pattern  rot_index)
  (let* ((filelist (cadr (file-glob pattern 1))))
    (while (not (null? filelist))
           (let* ((filename (car filelist))
                  (image (car (gimp-file-load RUN-NONINTERACTIVE filename filename)))
                   (drawable (car (gimp-image-get-active-layer image))))
;;              (plug-in-unsharp-mask RUN-NONINTERACTIVE   drawable radius amount threshold)
             (gimp-image-rotate image rot_index)
             (gimp-file-save RUN-NONINTERACTIVE  image drawable filename filename)
             (gimp-image-delete image))
           (set! filelist (cdr filelist))
    )
  )
)
