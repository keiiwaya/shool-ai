(defun fibonacci (n)
  (cond
   ((zerop n) 1)
   ((equal n 1) 1)
   (t        (+ (fib(fib(- n 1)) (fib(- n 2)))))))
