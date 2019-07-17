(defun depth1 (open goal rule)
 (progn
   (print open)
   (cond
     ((null open)          nil)
     ((eq (car open) goal) t)
     (t                    (depth1 (append (children (car open) rule)
                                           (cdr open))
                                   goal rule)))))
