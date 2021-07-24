(defun rec-reverse (%lst) 
  (cond ( (null %lst) nil)
		; car %lst を cdr %lstの末 に加えたもの
		(t (append (rec-reverse (cdr %lst)) (list (car %lst))))
		)
  )
