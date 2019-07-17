(defun breadth1 (open goal rule)
  (progn
   (print open)
   (cond
     ((null open)          nil)
     ((eq (car open) goal) t)
     (t                    (breadth1 (append (cdr open)
                                             (children (car open) rule))
                                      goal rule)))))
