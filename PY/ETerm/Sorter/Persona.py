from collections import Counter

class Persona():

    def __init__(self, doc, sur1, sur2, name1, name2, genre, bday, code):

        if doc is None:
            self.document = ""
        else:
            self.document = doc
        
        if sur1 is None:
            self.sur1 = ""
        else:
            self.sur1 = sur1.upper().strip()
        
        if sur2 is None:
            self.sur2 = ""
        else:
            self.sur2 = sur2.upper().strip()

        if name1 is None:
            self.name1 = ""
        else:
            self.name1 = name1.upper().strip()

        if name2 is None:
            self.name2 = ""
        else:
            self.name2 = name2.upper().strip()

        if genre is None:
            self.genre = ""
        else:
            self.genre = genre

        if bday is None:
            self.bday = ""
        else:
            self.bday = bday

        if code is None:
            self.code = ""
        else:
            self.code = code
        
        self.events = []

    def add_event(self, event, is_signed, time1, time2, time3, lector, auditorium):

        if event is None:
            event = ""
        
        if is_signed is None:
            is_signed = ""
        
        if lector is None:
            lector = ""
        
        if auditorium is None:
            auditorium = ""

        event_info = [event, is_signed, time1, time2, time3, lector, auditorium]

        self.events.append(event_info)

        self.events.sort(key=lambda x: x[2])
    
    def get_events_validity(self):

        if len(self.events)%2 != 0:
            return False

        prev = "Salida"

        for event in self.events:

            t = event[0]
            if t == prev:
                return False
            prev = t
        
        return True

       
        