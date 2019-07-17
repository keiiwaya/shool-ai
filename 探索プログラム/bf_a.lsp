(defun bf (start goal rule)
  (bf1 (list (list start 0 999999999)) goal rule))
