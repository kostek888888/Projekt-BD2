---1) Rollup liczba poszczegolnych gazet sprzedanych przez pracownikow, liczba sprzedanych przez pracownikow, liczba sprzedanych ogolem w salonie
SELECT id_salonu, Nvl(To_Char(id_sprzedawcy), 'sprzedanych w salonie') AS id_sprzedawcy,
       Nvl(To_Char(id_pisma),'przez pracownika') AS id_pisma,
       Count(id_pisma) AS liczba_sprzedanych
FROM sprzedaz
GROUP BY rollup (id_salonu, id_sprzedawcy, id_pisma);




--2) cube ile pism sprzedal sprzedawca w danym salonie
SELECT id_salonu, id_sprzedawcy, id_pisma, Count(id_pisma) AS ilosc_sprzedanych FROM sprzedaz
GROUP BY cube(id_salonu,id_sprzedawcy,id_pisma)
ORDER BY id_salonu; 

--3) grouping sets: jaki był przychód kazdego dnia w kazdym z salonow, jaki byl zbiorczy przychod w kazdym dniu oraz zbiorczy przychod w ciagu 3 miesiecy we wszystkich salonach
SELECT sprzedaz.id_salonu, sprzedaz.id_dnia,  Sum(sprzedaz.suma_zysku) AS zysk FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
HAVING id_dnia<85 OR id_dnia IS null
ORDER BY id_salonu, id_dnia;

--4) partycje i ruchome okno obliczeniowe
--jak wyglada sumaryczna sprzedaz w danym salonie w ostatnim miesiacu
SELECT id_salonu, id_dnia, suma_zysku AS zysk_dzienny, 
Sum(suma_zysku) OVER(
                    PARTITION BY id_salonu
                    ORDER BY id_dnia
                    RANGE BETWEEN unbounded preceding  AND CURRENT ROW
                    ) AS zarobek    
FROM sprzedaz
WHERE id_dnia <29;


--5)ranking sprzedawcow: ktory zarobil dla firmy najwiecej
SELECT id_sprzedawcy,
       Sum(suma_zysku) AS zysk,
       Rank() OVER (PARTITION BY NULL ORDER BY Sum(suma_zysku) desc) AS ranking
FROM sprzedaz
GROUP BY id_sprzedawcy;

