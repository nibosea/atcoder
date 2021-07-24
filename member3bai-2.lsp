(defun members3bai2 (%num %lst)
  (member %num %lst :test
		  #'(lambda (=x =y)
			  (equal (* 3 =x) =y))))
