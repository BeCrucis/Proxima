import os
import sys

class Nodo:

    def __init__(self):

        self.dato = None
        self.sig = None
        self.ant = None

class LinkedList:

    def __init__(self):

        self.inicial = None
    
    def __del__(self):

        del self.inicial
        
    def __repr__(self):

        if self.inicial is None:
            return "[]"

        string_list = "["
        current_node = self.inicial

        while current_node.sig is not self.inicial:
            string_list = f"{string_list}{current_node.dato}, "
            current_node = current_node.sig
        
        if current_node.dato is not self.inicial:
            string_list = f"{string_list}{current_node.dato}]"

        else:
            string_list = f"{string_list}]"
        
        return string_list
    
    def search_list_code(self, clave):

        anterior = None

        if self.inicial.dato >= clave:
            return anterior
        
        anterior = self.inicial

        while anterior.sig is not self.inicial and anterior.sig.dato < clave:
            anterior = anterior.sig
        
        return anterior
    
    def agregar(self):

        nuevo = Nodo()

        nuevo.dato = input("Entre la clave del nodo a agregar: ")

        try:
            nuevo.dato = int(nuevo.dato)
        except:
            print("La clave debe ser un entero!")
            return

        if self.inicial is None:
            self.inicial = nuevo
            nuevo.sig = self.inicial
        
        else:
            anterior = self.search_list_code(nuevo.dato)

            if anterior is None and nuevo.dato != self.inicial.dato:
                # Agrega un nodo como primero
                nuevo.sig = self.inicial
                nuevo.ant = self.inicial.ant
                self.inicial.ant.sig = nuevo
                self.inicial.ant = nuevo

                self.inicial = nuevo

            elif anterior is None or anterior.sig is not self.inicial and anterior.sig.dato == nuevo.dato:
                print("El nodo a agregar ya existe!")
            
            else:
                # Agrega un nodo en medio de la lista
                nuevo.sig = anterior.sig
                nuevo.ant = anterior

                anterior.sig = nuevo
                nuevo.sig.ant = nuevo
            
    
    def eliminar_nodo(self):

        deleted_data = input("Inserte la clave del nodo a eliminar: ")

        try:
            deleted_data = int(deleted_data)
        except:
            print("La clave debe ser un entero!")
            return
        
        anterior = self.search_list_code(deleted_data)

        if anterior is None or anterior.sig is self.inicial or anterior.sig.dato != deleted_data:

            if self.inicial.dato != deleted_data:
                print("El nodo no existe!")
            
            else:

                ultimo = self.inicial.ant

                if self.inicial == ultimo:
                    self.inicial = None
                else:
                    self.inicial = self.inicial.sig
                    self.inicial.ant = ultimo
                    ultimo.sig = self.inicial

                print(f"Borrado dato: {deleted_data}")
    
        else:
            anterior.sig = anterior.sig.sig
            anterior.sig.ant = anterior

            print(f"Borrado dato: {deleted_data}")
        

def main():
    
    lista = LinkedList()
    opcion = "0"

    while(opcion != "3"):

        print("Lista Circular Doblemente Encadenada!\n")
        print("1. Agregar objeto a lista")
        print("2. Eliminar objeto de lista")
        print("3. Salir\n")

        opcion = input("Inserte su opcion: ")

        if opcion == "1":
            lista.agregar()
            print(lista)
    
        if opcion == "2":
            lista.eliminar_nodo()
            print(lista)
        
        os.system("pause")
        os.system("cls")

main()
