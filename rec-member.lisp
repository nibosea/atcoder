(defun rec-member (%atm %lst)
  (cond ((null %lst) nil)
		((eq %atm (car %lst)) %lst)
		(t (rec-member %atm (cdr %lst)))
		)
  )

