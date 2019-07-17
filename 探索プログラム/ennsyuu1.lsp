(defun hantei (x y a d m l)
  (cond
   ((= y a) (car x))
   ((= y d) (cdr x))
   ((= y m) (max x))
   ((= y l) (length x))
   (t 'dekimasen)))
