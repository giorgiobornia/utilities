
(define (squarify_image filename-in)
 (let* (
  (image      (car (gimp-file-load RUN-NONINTERACTIVE filename-in "")))
  (drawable   (car (gimp-image-active-drawable image)))
  (cur-width  (car (gimp-image-width image)))
  (cur-height (car (gimp-image-height image)))
  (max_dim      (max cur-width cur-height))
  (gimp-image-insert-layer image layer_new 0 -1) ;; create a layer with black color
  ;;all definitions must be inside a let 
   )
   (display max_dim)
   (gimp-layer-resize layer_new max_dim max_dim 0 0) ;; resize the layer 
;; put the new layer below
;; fit canvas to layers
;; flatten image 
;; offset the image layer to the center
  )
)
