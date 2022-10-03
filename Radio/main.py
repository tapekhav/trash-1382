#python
class Radio:
    __stationRequired__ = set()
    __stations__ = {}
    __result__ = set()

    def readRequiredStation(self):
        self.__stationRequired__ = set(input().split(','))

    def readStations(self):
        for _ in range(int(input())):
            id, cover = input().split(':')
            self.__stations__[int(id)] = set(cover.split(','))

    def calculateStation(self):
        while self.__stationRequired__:
            bigestStation = None
            stationCovered = set()
            for id, cover in self.__stations__.items():
                passableCover = set(self.__stationRequired__) & set(cover)
                if len(passableCover) > len(stationCovered):
                    bigestStation = id
                    stationCovered = passableCover

            self.__stationRequired__ = set(self.__stationRequired__) - set(stationCovered)
            self.__result__.add(bigestStation)
        self.__result__ = sorted(self.__result__)

    def getResult(self):
        return self.__result__


def main():
    radio = Radio()
    radio.readRequiredStation()
    radio.readStations()
    radio.calculateStation()
    print(','.join(map(lambda x: str(x), radio.getResult())))


if __name__ == '__main__':
    main()
