(defun children (node rule)
  (cond
    ( (null rule)              nil)
	( (equal node (caar rule)) (cons (cadar rule)
									 (children node (cdr rule))))
	(t                         (children node (cdr rule)))))