SELECT Nvl(To_Char(id_salonu),'Wszystkie salony') AS id_salonu,
       Nvl(To_Char(id_pisma),'Ogolem pism') AS id_pisma,
       Count(id_pisma) AS liczba_sprzedanych
FROM sprzedaz
GROUP BY rollup (id_salonu, id_pisma);

SELECT  Nvl(To_Char(id_salonu),'Wszystkie salony') AS id_salonu,
			  Nvl(To_Char(id_sprzedawcy),'Sprzedawcy') AS id_sprzedawcy_w_salonie,
       Count(id_paragonu) AS liczba_obsluzonych_klientow
FROM sprzedaz
GROUP BY rollup (id_salonu,id_sprzedawcy);


SELECT  Nvl(To_Char(id_salonu),'salon') AS id_salonu,
        Nvl(To_Char(id_sprzedawcy),'sprzedawcy') AS id_sprzedawcy,
        Nvl(To_Char( id_pisma),'pism') AS  id_pisma,
        Count(id_pisma) AS ilosc_sprzedanych FROM sprzedaz
GROUP BY cube(id_salonu,id_sprzedawcy,id_pisma)
ORDER BY id_salonu,id_sprzedawcy,id_pisma asc;

SELECT Nvl(To_Char(id_sprzedawcy),'Wszystkie sprzedawcy') AS id_sprzedawcy,
       Nvl(To_Char(id_dnia),'w miesiacu') AS id_dnia,
       Sum(suma_zysku) AS suma_zysku FROM sprzedaz
GROUP BY cube(id_sprzedawcy,id_dnia)
HAVING id_dnia<=28;
ORDER BY id_sprzedawcy, id_dnia asc;


SELECT  Nvl(To_Char(sprzedaz.id_salonu),'Wszystkie salony') AS id_salonu,
       sprzedaz.id_dnia,  Count(sprzedaz.id_sprzedazy) AS liczba_sprzedanych_gazet FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
ORDER BY id_salonu desc, id_dnia;

SELECT Nvl(To_Char(sprzedaz.id_salonu),'Wszystkie salony') AS id_salonu,
       sprzedaz.id_dnia,  Sum(sprzedaz.suma_zysku) AS zysk FROM sprzedaz
GROUP BY Grouping sets ((id_salonu,id_dnia), id_dnia ,())
ORDER BY id_salonu desc , id_dnia;


SELECT id_salonu, id_dnia, suma_zysku AS zysk_dzienny,
Sum(suma_zysku) OVER(
                    PARTITION BY id_salonu
                    ORDER BY id_dnia
                    RANGE BETWEEN unbounded preceding  AND CURRENT ROW
                    ) AS zarobek
FROM sprzedaz
WHERE id_dnia <29;

SELECT id_salonu, id_sprzedawcy, id_pisma AS id_pisma,
Count(id_pisma) OVER(
                    PARTITION BY id_salonu
                    ORDER BY id_dnia, id_pisma asc
                    RANGE BETWEEN unbounded preceding  AND CURRENT ROW
                    ) AS liczba_sprzedanych_pism
FROM sprzedaz
WHERE id_dnia <29;



SELECT id_sprzedawcy,
       Sum(suma_zysku) AS zysk,
       Rank() OVER (PARTITION BY NULL ORDER BY Sum(suma_zysku) desc) AS ranking
FROM sprzedaz
GROUP BY id_sprzedawcy;

SELECT id_pisma,
       Count(id_pisma) AS liczba_sprzedanych,
       Rank() OVER (PARTITION BY NULL ORDER BY  Count(id_pisma) desc) AS ranking
FROM sprzedaz
GROUP BY id_pisma;

