				Tema1 2024 SDA

Tema propusă presupune implementarea unui sistem care simulează un trenuleț cu vagoane, folosind o structură de date de tip listă dublu înlănțuită circulară. Fiecare vagon al trenului poate fi inscripționat cu un caracter și mecanicul se poate deplasa între vagoane, modificând sau interacționând cu vagoanele pe care le întâlnește. Mai exact, se dorește modelarea unui trenuleț cu posibilități de mișcare a mecanicului și de manipulare a vagoanelor în diverse moduri.

Componentele principale:
Trenul: Este reprezentat de o listă dublu înlănțuită circulară, în care fiecare nod reprezintă un vagon. Fiecare vagon poate conține un caracter inscripționat, iar mecanicul este plasat într-un vagon. Mecanicul poate călători între vagoane.
Mecanicul: Poate fi mutat la vagonul din stânga sau dreapta. De asemenea, poate modifica caracterul inscripționat al vagonului în care se află sau poate cupla/decupla vagoane.
Funcționalități
Mișcarea mecanicului: Mecanicul poate fi deplasat într-un vagon vecin din stânga sau din dreapta. În cazul în care mecanicul ajunge la capătul trenului, mișcarea este circulară, adică se mută în direcția opusă.
Actualizarea caracterului vagonului: Mecanicul poate schimba caracterul inscripționat pe vagonul în care se află.
Cuplarea și decuplarea vagoanelor: Vagoanele pot fi cuplate la stânga sau dreapta mecanicului, iar decuplarea se poate face prin eliminarea vagonului curent.
Căutarea unui șir de caractere: Există operațiuni care permit căutarea unui șir de caractere într-o secvență de vagoane, iar mecanicul se mută la vagonul care conține ultimul caracter din șirul găsit.
Vizualizarea trenului: Utilizatorii pot vedea starea actuală a trenului, cu caracterul vagonului în care se află mecanicul marcat special.
Tipuri de Comenzi
Proiectul include mai multe tipuri de comenzi care pot fi utilizate pentru a manipula trenul și mecanicul:

UPDATE: Permite mișcarea mecanicului, schimbarea caracterului unui vagon sau cuplarea/decuplarea vagoanelor.
SEARCH: Căutarea unui șir de caractere într-o secvență de vagoane.
QUERY: Permite vizualizarea caracterului vagonului curent sau a întregului tren.
EXECUTE: Execută comenzile adăugate într-o coadă de comenzi.
Aceste operațiuni vor fi testate și implementate folosind o coadă de comenzi care gestionează ordinea în care sunt efectuate. Funcționalitatea principală include și managementul eficient al resurselor de memorie prin utilizarea corectă a listelor dublu înlănțuite.






