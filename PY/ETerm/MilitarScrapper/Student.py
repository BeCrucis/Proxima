from bs4 import BeautifulSoup

class Student:

    def __init__(self, name = None):

        if name:
            self.add_name(name)
        else:

            self.raw_name = ''
            self.surnames = ''
            self.names = ''

        self.id = None
        self.oed_observations = []
        self.ed_observations = []
        self.is_suspended = False
        self.grade = 10

    def add_name(self, name):

        if not self.raw_name:
            self.raw_name = name
            processed_name = name.split(',')
            self.surnames = processed_name[0].strip().upper()
            self.names = processed_name[1].strip().upper()
        
    
    def add_oed_observation(self, observation_date, year = None, level = 1):

        if not year:
            year = ''    
        else:
            year = str(year)

        if year in observation_date:
            self.oed_observations.append(observation_date)
            self.grade -= 0.5


    def add_ed_observation(self, observation_date, year = None):

        if not year:
            year = ''    
        else:
            year = str(year)

        if year in observation_date:
            self.ed_observations.append(observation_date)
    
    def import_student_info(self, driver, info_link):
        if driver.current_url != info_link:
            driver.get(info_link)
        
        student_info = driver.find_elements_by_css_selector("span[person_role=\"estudiante\"]")[0]
        student_name = student_info.get_attribute("innerHTML")
        student_id = int(student_info.get_attribute("id").split('_')[2])

        self.add_name(student_name)
        self.id = student_id
        
    
    def import_oed_info(self, driver, oed_link, year, term):

        if driver.current_url != oed_link:
            driver.get(oed_link)

        # If the student still has not name
        if not self.raw_name:
            self.import_student_info(driver, oed_link)
        
        dates = driver.find_elements_by_css_selector("td[class =\"poll record fixedrow sel\"]")

        if dates:

            soup = BeautifulSoup(driver.page_source, features="lxml")
            elements = soup.find_all("tr")

            observerEntries = elements[4:]

            for entry in observerEntries:
                entryData = entry.findChildren("td" , recursive=False)
                if term.upper() in entryData[5].text.upper():
                    rawFecha = entryData[2].text
                    formattedFecha = rawFecha[:10]

                    self.add_oed_observation(formattedFecha, year)
    
    def import_ed_info(self, driver, ed_link, year):

        if driver.current_url != ed_link:
            driver.get(ed_link)

        # If the student still has not name
        if not self.raw_name:
            self.import_student_info(driver, ed_link)
        
        dates = driver.find_elements_by_css_selector("td[class =\"poll record fixedrow sel\"]")

        if dates:

            soup = BeautifulSoup(driver.page_source, features="lxml")
            elements = soup.find_all("tr")

            observerEntries = elements[4:]

            for entry in observerEntries:
                entryData = entry.findChildren("td" , recursive=False)
                rawFecha = entryData[2].text
                formattedFecha = rawFecha[:10]
                self.add_ed_observation(formattedFecha, year)

    def __repr__(self):
        student_info = f'{self.surnames} {self.names}'
        return student_info
