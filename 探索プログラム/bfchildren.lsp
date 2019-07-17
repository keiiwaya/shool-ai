(defun children (node rule)
  (cond
   ((null rule) '())
   ((equal node (caar rule))
	         (cons (cdar rule) (children node (cdr rule))))
   (t        (children node (cdr rule)))))
