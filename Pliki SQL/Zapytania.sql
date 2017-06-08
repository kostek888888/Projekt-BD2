---1)ROLLUP ile kazdego z pism zostalo sprzedanych w danym salonie, ile ogolem pismy bylo sprzedanych w danym salonie, ile pism zostalo sprzedanych we wszystkich salonach
SELECT Nvl(To_Char(id_salonu),'Wszystkie salony') AS id_salonu,
       Nvl(To_Char(id_pisma),'Ogolem pism') AS id_pisma,
       Count(id_pisma) AS liczba_sprzedanych
FROM sprzedaz
GROUP BY rollup (id_salonu, id_pisma);

--ile klientow bylo obsluzonych w danym salonie przez jakiego sprzedawce, ogolem w salonie, ogolem obsluzonych klientow
SELECT  Nvl(To_Char(id_salonu),'Wszystkie salony') AS id_salonu,
			  Nvl(To_Char(id_sprzedawcy),'Sprzedawcy') AS id_sprzedawcy_w_salonie,
       Count(id_paragonu) AS liczba_obsluzonych_klientow
FROM sprzedaz
GROUP BY rollup (id_salonu,id_sprzedawcy);


--2) cube ile pism sprzedal sprzedawca w danym salonie
<<<<<<< HEAD
SELECT  Nvl(To_Char(id_salonu),'salon') AS id_salonu,
        Nvl(To_Char(id_sprzedawcy),'sprzedawcy') AS id_sprzedawcy,
        Nvl(To_Char( id_pisma),'pism') AS  id_pisma,
        Count(id_pisma) AS ilosc_sprzedanych FROM sprzedaz
GROUP BY cube(id_salonu,id_sprzedawcy,id_pisma)
ORDER BY id_salonu,id_sprzedawcy,id_pisma asc;
=======
SELECT id_salonu, 
   Nvl(To_Char(id_sprzedawcy),'Wszyscy sprzedawcy') AS id_sprzedawcy,
   Nvl(To_Char(id_pisma),'Wszystkie pisma') AS wszystkie_pisma,
   Count(id_pisma) AS ilosc_sprzedanych FROM sprzedaz
  GROUP BY cube(id_salonu,id_sprzedawcy,id_pisma)
  ORDER BY id_salonu;
>>>>>>> origin/master

---ile sprzedawca zarobil dla firmy na poszczegolnym pismie, ile zarobil na wszystkich pismach, ile wszyscy sprzedawcy zarobili na danym pismie i ogolny zarobek wszystkich sprzedawcow na wszystkich pismach
SELECT Nvl(To_Char(id_sprzedawcy),'Wszystkie sprzedawcy') AS id_sprzedawcy,
       Nvl(To_Char(id_dnia),'w miesiacu') AS id_dnia,
       Sum(suma_zysku) AS suma_zysku FROM sprzedaz
GROUP BY cube(id_sprzedawcy,id_dnia)
HAVING id_dnia<=28;
ORDER BY id_sprzedawcy, id_dnia asc;


--3) grouping sets: liczba sprzedanych gazet we wszystkich salonach danego dnia, ogolem sprzedanych gazet, a potem sprzedanych gazet danego dnia w danym salonie
SELECT  Nvl(To_Char(sprzedaz.id_salonu),'Wszystkie salony') AS id_salonu,
       sprzedaz.id_dnia,  Count(sprzedaz.id_sprzedazy) AS liczba_sprzedanych_gazet FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
ORDER BY id_salonu desc, id_dnia;

--- Suma zysku danego dnia we wszystkich salonach, suma calkowitego zysku, a potem zysk dzienny dla kazdego salonu kazdego dnia
SELECT Nvl(To_Char(sprzedaz.id_salonu),'Wszystkie salony') AS id_salonu,
       sprzedaz.id_dnia,  Sum(sprzedaz.suma_zysku) AS zysk FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
ORDER BY id_salonu desc , id_dnia;


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

--ile pism sprzedal sprzedawca w danym dniu i jakie to byly pisma
SELECT id_salonu, id_sprzedawcy, id_pisma AS id_pisma,
Count(id_pisma) OVER(
                    PARTITION BY id_salonu
                    ORDER BY id_dnia, id_pisma asc
                    RANGE BETWEEN unbounded preceding  AND CURRENT ROW
                    ) AS liczba_sprzedanych_pism
FROM sprzedaz
WHERE id_dnia <29;



--5)ranking sprzedawcow: ktory zarobil dla firmy najwiecej
SELECT id_sprzedawcy,
       Sum(suma_zysku) AS zysk,
       Rank() OVER (PARTITION BY NULL ORDER BY Sum(suma_zysku) desc) AS ranking
FROM sprzedaz
GROUP BY id_sprzedawcy;

---ranking liczby sprzedanych pism
SELECT id_pisma,
       Count(id_pisma) AS liczba_sprzedanych,
       Rank() OVER (PARTITION BY NULL ORDER BY  Count(id_pisma) desc) AS ranking
FROM sprzedaz
GROUP BY id_pisma;

