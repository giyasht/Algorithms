(define (fib-iter x xi y1 y2 y3)
  (cond ((= x xi) (+ y1 (* 2 y2) (* 3 y3)))
        (else (fib-iter x (+ xi 1) (+ y1 (* 2 y2) (* 3 y3)) y1 y2))
        ))

(define (fib-it x) 
  (if (< x 3) x (fib-iter x 3 2 1 0)))

(fib-it 6)