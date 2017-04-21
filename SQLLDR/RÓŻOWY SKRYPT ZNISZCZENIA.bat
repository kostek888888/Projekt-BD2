@color d
@echo przy kazdym zaladowaniu nowych plikow najlepiej jest sobie wyczyscic baze czyli odpalic calego create'a w sqltools
@echo to usunie wszystkie wpisy



@echo podaj login do bazy
@set /p login=">> "

@echo podaj haslo do bazy
@set /p haslo=">> "



sqlldr userid=%login%/%haslo% control=sprzedawca.ctl

sqlldr userid=%login%/%haslo% control=tematyka.ctl
sqlldr userid=%login%/%haslo% control=pismo.ctl


sqlldr userid=%login%/%haslo% control=rok.ctl
sqlldr userid=%login%/%haslo% control=miesiac.ctl
sqlldr userid=%login%/%haslo% control=dzien.ctl


sqlldr userid=%login%/%haslo% control=miasto.ctl
sqlldr userid=%login%/%haslo% control=salon.ctl


sqlldr userid=%login%/%haslo% control=platnosci.ctl
sqlldr userid=%login%/%haslo% control=paragony.ctl

sqlldr userid=%login%/%haslo% control=sprzedaz.ctl



@pause
@exit

