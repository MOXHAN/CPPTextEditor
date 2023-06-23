# CPPTextEditor

### Projektteilnehmer
Maxim Hansen - 937236

### Projektbeschreibung
Das Ziel des Projektes war es einen simplen Texteditor zu erstellen. Der erstellte 
Editor hat die folgenden Features:
- Einfacher Text - Input durch die Tastatur
- Formatierung in Form von Bold, Italic/Kursiv, Underline, gelbe Markierung
- Markierung der aktuellen Zeile
- Shortcuts Strg+C (Copy) und Str+V (Paste)
- Speichern als Txt-file
- Laden von Txt-file
- Exportieren zu PDF (ohne Formatierung)
- Suchfunktion (gesuchtes Wort wird im Text markiert)
- Gleichzeitiges Öffnen von mehreren Dokumenten und Navigation über Reiter
- Pop-Up Abfrage "Speichern, wenn Schließen der App"
- Pop-Up Abfrage "Zuletzt gespeichertes Dokument öffnen" beim Starten der App
- Dump des Dokumenteninhalts auf die Konsole
- Console-Logging 

### Dependencies

Externe Libraries: Qt

### Anleitung zum Bauen unter msys2/mingw64

### Anforderungen

| Anforderungs Nr.                                   | Wie gelöst                                                                                                            | Wo zu finden                                          |
|----------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------|
| Erzeugen eigener Bibliothek                        | Erstellung der Library "Handlerlib"                                                                                   | Subdirectory "Handlerlib"                             |
| Verwendung externer Bibliotheken                   | Verwendung der Qt Library                                                                                             |                                                       |
| Funktionsüberladung                                |                                                                                                                       | FileHandler.cpp -> Funktion "handleLoad"              |
| Operatorüberladung                                 | Überladung des << Operators für Qt Class                                                                              | FileHandler.cpp                                       |
| Datei und Konsolen IO                              | Console Logging in allen Klassen der "Handlerlib" und Datei-Logging durch "speichern als .txt"                        ||
| Verwendung von C++ Smart Pointern                  | Wurde aufgrund der eigenen Speicherverwaltung von Qt nur beispielhaft einmal umgesetzt                                | MainWindow.cpp, Zeile 52                              |
| Verwendung von weiteren std Containern             | Verwendung std::unordered_map                                                                                         | DocumentHandler.h, Zeile 24                           |
| Verwendung von Laufzeitpolymorphismus              | Verwendung der Parent-Class "QTextEdit" statt der eigens implemntierten Child-Class in allen Klassen der "Handlerlib" | Handlerlib                                            |
| Nutzung von move-Semantik                          | Der Inhalt des QTextDocuments wird als rvalue übergeben und auf die Konsole ausgegeben                                | MainWindow.cpp, Zeile 76                              |
| Vermeidung von "rohen" Zeigern                     | Außerhalb der Verwendung von Zeigern im Zusammenhang mit der Qt Library wurden keine rohen Zeiger verwendet           |                                                       |
| Erstellung einer Template Klasse und/oder Funktion | Funktion "print()", die die Konsolenausgaben Syntax vereinfacht ( print(text) statt std::cout << text usw. )          | ToolHandler.cpp, Zeile 19ff                           |
| Profiling                                          | Ergebnisse weiter unten                                                                                               |                                                       |
| Versionskontrolle mit Git                          | Github Repo erstellt                                                                                                  | https://github.com/MOXHAN/CPPTextEditor#cpptexteditor |
| Linting mit Clang-Tidy                             | Linting wurde während der Entwicklung durch eingebaute Vorschläge verwendet                                           |                                                       |
| Min. 500 Zeilen Code                               | ~800 Non-Comment Lines of Code                                                                                        |                                                       |
| Readme.md Datei erstellen                          | Diese Datei                                                                                                           |                                                       |


### profiling Ergebnisse 

Ich bezweilfe ehrlich gesagt, ob ich das Profiling richtig ausgeführt habe, leider gibt es auf WIndows
nicht die Möglichkeit das Ganze innerhalb von CLion zu machen, daher hab ich
nach Ratschlägen auf StackOverflow auf "VerySleepy" zurückgegriffen. Die Ergebnisse sind in einer CSV-Datei im Verzeichnis.

### Projektstruktur und Klassenhierarchie

Der Code ist in 2 Directories aufgeteilt. Die erstellte Library "Handlerlib" ist im sub-directory "Handlerlib" zu finden.

Die GUI besteht aus den folgenden Klassen:
- MainWindow, erbt von/eigene Implementierung von QMainWindow
- EditorWidget, erbt von/eigene Implementierung von QTextEdit
- LineNumberArea, erbt von QWidget
- FileDocker, erbt von QDockWidget

Dazu kommt noch das PopUpWindow, welches für verschiedene Pop-Up Windows gebraucht wird
und von QDialog erbt.

In der Library "Handlerlib" gibt es die folgenden Klassen:
- FileHandler
- ToolHandler
- TableHandler
- DocumentHandler
Diese Klassen erben alle von QObject, um auf die Funktionalitäten von Qt zugreifen
zu können.

### Herausforderungen
Die größte Herausforderung war es, sich in die Qt Library einzuarbeiten, da diese sehr
umfangreich ist. Oft hat es ein bisschen Recherche gebraucht, um die passende Klasse
für das aktuelle Problem zu finden.
Eine weitere Herausforderung war die sinnvolle Trennung von GUI und Funktionalität.
Ich bin aber der Überzeugung dies gut hinbekommen zu haben. Dabei hat vor allem
die Erstellung der "Handlerlib" geholfen.

### Limitationen, Known-Bugs und Ausblick

- Undo/Redo funktioniert nicht
- Beim Suchen nach Wörtern wird beim n+1-ten Mal Suchen (n = Häufigkeit des Suchbegriffes) nichts angezeigt,
wenn dann wieder gesucht wird, geht es beim Anfang des Dokumentes wieder los
- Export zu PDF ohne Formatierung
- Export zu PDF fehlerhaft, wenn die Zeilenlänge zu groß ist. Dies passiert, da der Editor
so ausgelegt ist, dass es einen Horizontal-Scroll gibt, statt einer Zeilenlängenbegrenzung
- Wenn mehrere Tabellen in einem Dokument erschaffen wurden, gibt es keine Möglichkeit
zu bestimmen welche mit den Buttons "addRow" und "addCol" erweitert werden soll
- Das Feature mehrere Dokumente gleichzeitig zu öffnen hat noch Fehleranfälligkeiten im Bereich der Buttons.
Damit das Feature funktioniert, muss immer das Dokument abgespeichert werden, bevor ein neues
geöffnet wird und wenn ein neues geöffnet ist und dieses nicht abgespeichert wird durch
das Drücken des + Buttons, wird der Button für dieses Dokument nicht funktionieren, da kein
Link hinterlegt ist

Mögliche Weitere Features:
- Export zu PDF Probleme beheben
- Mehr Formatierungs Möglichkeiten
- Themes
- Bilder einfügen
- Tabellenfunktion verbessern (Probleme bei mehreren Tabellen)

### Selbsteinschätzung

Da ich alleine an diesem Projekt gearbeitet habe, macht dieser Punkt wenig Sinn. Ich
möchte dazu nur schreiben, dass ich zur Planung des Projektes ein Kanban-Board genutzt habe
und mir das sehr geholfen hat den Überblick sowohl über meinen Fortschritt als auch
meine geplanten Features und bestehenden Probleme zu behalten. Die Zeiteinteilung ist mir tatsächlich
sehr gut gelungen, da ich seit den IDW regelmäßig am Projekt gearbeitet habe.