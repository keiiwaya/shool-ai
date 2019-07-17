(defun kaijou (x)
  (cond
   ((zerop x) 1)
   ((equal x 1) 1)
   (t (* x (kaijou (1- x))))))
  
