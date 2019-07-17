(defun lap (x)
  (cond
    ((null x)       t)
    ((atom (car x)) (lap (cdr x)))
    (t nil)))

(defun menberp (x y)
  (cond
    ((null x) nil)
    ((equal (car x) 'y) t)
    (t (menberp (cdr x) y))))

//yがxの中になんこあるか数える関数
(defun kazu (x y)
  (cond
    ((null x) 0)
    ((equal (car x) y) (1+ (kazu (cdr x) y)))
    (t (kazu (cdr x) y))
    ))
