---Rollup suma zyskow dla sprzedawcow i salonow
SELECT id_salonu, id_sprzedawcy, Sum(suma_zysku) AS Zysk FROM sprzedaz
GROUP BY rollup(id_salonu, id_sprzedawcy, suma_zysku );

--cube ile pism sprzedal sprzedawca w danym salonie
SELECT id_salonu, id_sprzedawcy, id_pisma, Count(id_pisma) FROM sprzedaz
GROUP BY cube(id_salonu,id_sprzedawcy,id_pisma)
ORDER BY id_salonu; 

--grouping sets: jaki był przychód kazdego dnia w kazdym z salonow, jaki byl zbiorczy przychod w kazdym dniu oraz zbiorczy przychod w ciagu 3 miesiecy we wszystkich salonach
SELECT sprzedaz.id_salonu, sprzedaz.id_dnia,  Sum(sprzedaz.suma_zysku) AS zysk FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
HAVING id_dnia<85 OR id_dnia IS null
ORDER BY id_salonu, id_dnia;
