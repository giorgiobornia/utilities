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
             (gimp-image-delete image))
           (set! filelist (cdr filelist)))))
