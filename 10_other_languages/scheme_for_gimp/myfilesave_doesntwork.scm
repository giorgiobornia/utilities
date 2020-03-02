;;  gimp -i -b '(myfilesave "*.gif")' -b '(gimp-quit 0)'

;; rot_index   ROTATE-90 (0), ROTATE-180 (1), ROTATE-270 (2) 

;; seems like this script does not work if you provide an explicit list in 'pattern',
;; other than "*.tif"

(define (myfilesave  pattern)
  (let* ((filelist (cadr (file-glob pattern 1))))
    (while (not (null? filelist))
           (let* ((filename (car filelist))
                  (image (car (gimp-file-load RUN-NONINTERACTIVE filename filename)))
                   (drawable (car (gimp-image-get-active-layer image))))
;;              (plug-in-unsharp-mask RUN-NONINTERACTIVE   drawable radius amount threshold)
             (file-jpeg-save RUN-NONINTERACTIVE image drawable filename filename 0.90 0 1 0 "Mathias Lindner" 0 1 0 0)
;;              (gimp-image-rotate image rot_index)
;;              (gimp-file-save RUN-NONINTERACTIVE  image drawable filename filename)
;;               (gimp-image-delete image)
            )
           (set! filelist (cdr filelist)))))
