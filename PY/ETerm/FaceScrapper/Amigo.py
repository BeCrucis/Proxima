from selenium import webdriver
import time

class Amigo:

    def __init__(self,  driver, friend_id):
        

        friends_link = f'https://www.facebook.com/{friend_id}/friends'
        # Primero se accede a la pagina de facebook
        if driver.current_url != friends_link:
            driver.get(friends_link)

        # Se extrae el nombre
        # friends = driver.find_elements_by_class_name("oo9gr5id")

        # while not friends:
        #     friends = driver.find_elements_by_class_name("oo9gr5id")
        #     time.sleep(1)

        # temp = []
        # # Filtra los nombres para obtener solo los validos
        # for friend in friends:
        #     friend_name = friend.text

        #     if friend_name not in ('', 'Amigos', 'Fotos', 'Editar perfil'):
        #         temp.append(friend_name)

        # f = driver.find_elements_by_class_name("gpro0wi8")

        # for name in f:
        #     if 'Oscar' in name.text:
        #         print('AAAAAAA')
        #         input('Enter para continuar ')

        # self.name = temp[2]
