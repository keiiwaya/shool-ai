(defun sortdemo ()
  (let
      ((unsorted '((2 a) (1 b) (4 c))))

	(princ "unsorted : ")
	(princ unsorted)
	(terpri)
	(setq sorted (sort unsorted '> :key #'car))
	(princ "sorted   : ")
	(princ sorted)
	(terpri)))
