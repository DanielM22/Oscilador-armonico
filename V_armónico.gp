clear
set xl "x"
set yl "{/Symbol f}"
set yr [0:2.5]
set grid
p "EigenFuncion.dat" u 1:2 w l ls 3 t "|{/Symbol f}|^2", "EigenFuncion.dat" u 1:3 w l t "{/Symbol r}" ls 7
