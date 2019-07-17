(defun ruijou (x n) (cond
                      ((zerop n) 1)
                      ((equal x 1) 1)
                      (t (* x (ruijou x (1- n))))))
			    
	      
