(defun nibeki2 (%num)
  (do ( (=i 0 (1+ =i) )
	   (=ans 1))
		((eq =i %num) =ans)
		;式1~n
		(setq =ans (* =ans 2))
		)
  )

		
