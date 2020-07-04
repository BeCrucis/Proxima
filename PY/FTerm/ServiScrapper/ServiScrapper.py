from selenium import webdriver
import os

# URL_PREFIX = 'https://www.servientrega.com/wps/portal/Colombia/transacciones-personas/rastreo-envios/detalle?id=9115625'
URL_PREFIX = 'https://mobile.servientrega.com/WebSitePortal/RastreoEnvioDetalle.html?Guia=9115625'
# URL_SUFFIX = '&tipo=0'
URL_SUFFIX = ''

# https://mobile.servientrega.com/WebSitePortal/RastreoEnvioDetalle.html?Guia=9115625700

def main():

    chrome_options = webdriver.ChromeOptions()
    chrome_options.add_argument('--proxy-server=104.154.143.77:3128')
    driver = webdriver.Chrome('F:/Downloads/Carpetas/Utility/Temp/chromedriver83.exe', options=chrome_options)

    id_range = list(range(750, 900))

    for id_number in id_range:

        driver.get(f'{URL_PREFIX}{id_number}{URL_SUFFIX}')

        name = driver.find_elements_by_id('lblRemitente')

        if name:
            name = name[0].text.lower()
        else:
            print(f'NO NOMBRE : {id_number}')
            continue
        
        if 'aurora' in name:
            print(id_number)
            os.system('pause')
        
        else:
            print(f'{name} : {id_number}')


if __name__ == "__main__":
    main()
