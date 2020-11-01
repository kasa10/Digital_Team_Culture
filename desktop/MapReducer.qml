import QtQuick 2.0
import QtLocation 5.12
import QtPositioning 5.12


Item
{
    Map {
        anchors.fill: parent
        plugin:  Plugin {
            id: mapPlugin
            name: "osm"
        }
        center: QtPositioning.coordinate(55.753215, 37.622504)
        zoomLevel: 14

        MapStationItem{
            longitude: 55.744526
            latitude:  37.545267
            stationName: "29.10.2020 13:30:00"
            stationSubName: "Встреча писателя с приглашенными в формате диалога."
            anomalesCount: "Творческая встреча с современным российским писателем"
            isOnControl: "Кутузовский просп. 24"
        }

        MapStationItem{
            longitude: 55.774558
            latitude:  37.593857
            stationName: "25.11.2020 14:00:00"
            stationSubName: "Творчество А. Блока"
            anomalesCount: ""
            isOnControl: "ул. 4-я Тверская-Ямская, д. 26/8"
        }

        MapStationItem{
            longitude: 55.623961
            latitude:  37.539060
            stationName: "01.01.2020"
            stationSubName: "Вдохновение Ясенево"
            anomalesCount: ""
            isOnControl: "Москва,  ул. Профсоюзная, д.123А"
        }

        MapStationItem{
            longitude: 55.869723
            latitude:  37.683230
            stationName: "22.10.2020 17:00:00"
            stationSubName: "Я, мама, папа - дружная семья!"
            anomalesCount: ""
            isOnControl: "Москва,  Шушенская ул. 7"
        }

        MapStationItem{
            longitude: 55.759370
            latitude:  37.564527
            stationName: "17.11.2020"
            stationSubName: "Правила дорожные детям знать положено"
            anomalesCount: ""
            isOnControl: "Нововаганьковский пер. 22"
        }
    }
}


