# ha5kfu-SDR-gyak

A szoftverrádiós gyakorlaton egy egyszerű FM vevőt írunk, amely egy RTL-SDR-ből érkező IQ minták demodulálására alkalmas. A feladatot [GNU Radio](https://www.gnuradio.org/)-val és C-ben is megoldjuk. Kiindulásnak, illetve bemutató céllal egy-egy repsávos AM vevő is rendelkezésre áll.

A szoftverradios_gyak.pdf dokumentum egy rövid elméleti összefoglalót tartalmaz és a feladat leírását.

A repóban 4 mappa van:
- grc: GNU Radio fileok
- am: a C-ben írt, példa AM vevő
- fm: az FM vevő kiindulási filejai
- server: a két TCP szerver indítófile-ja, ezt mi futtatjuk a klubszobában

A [megoldás branch](https://github.com/simonyiszk/ha5kfu-SDR-gyak/tree/megoldas)-en elérhetőek a megoldások is.

A jelfeldolgozó lánc:
```
+------------------+      +-----------------+      +--------------------+      +-----------+
|     IQ minta     |      | FM demoduláció  |      | szűrés + decimálás |      | Lejátszás |
|      forrás      | -->> |  (te írod meg)  | -->> |   (15kHz, 48ksps)  | -->> |           |
| (rtl_sdr/nc/cat) |      | (tcc fmdemod.c) |      |       (sox)        |      |  (aplay)  |
+------------------+      +-----------------+      +--------------------+      +-----------+
```

A `parancs.sh` scripttel indítható a C-ben írt vevő:
- saját rtl-sdr esetén: `./parancs.sh rtl`
- megosztott rtl-sdr esetén: `./parancs.sh`
- "konzerv" IQ mintákkal: `./parancs.sh iq`

A demodulátort az `fmdemod.c` fileba kell megírni.

Szükséges szoftverek:
- `git` (ezen repó klónozásához)
- `rtl_sdr` (saját eszközhöz)
- `nc` (netcat) a megosztott szerver eléréséhez
- `tcc` (a demodulátor futtatásához)
- `sox` (a jelfeldolgozáshoz)
- `aplay` (a hang lejátszásához)

Jó munkát!

HA7DN 2025
