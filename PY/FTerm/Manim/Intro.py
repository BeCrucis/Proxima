from manimlib.imports import *

class Intro(Scene):

    def construct(self):

        by_text = TextMobject('By:')

        gamma = TexMobject(r'\gamma')
        gamma.scale(5)
        gamma.set_color(COLOR_MAP['LIGHT_GREY'])

        by_text.next_to(gamma, LEFT, buff=0.2)
        by_text.shift(UP*0.5)

        self.play(Write(by_text))
        self.play(Write(gamma))
        self.wait()

        euler = TexMobject(r'\textit{e}')
        euler.scale(5)
        euler.set_color(COLOR_MAP['GREEN_A'])

        self.play(ApplyMethod(by_text.next_to, euler, LEFT, buff=SMALL_BUFF))
        self.play(Transform(gamma, euler))

        self.wait(2)

        self.play(FadeOut(by_text), FadeOut(gamma))
        self.wait(1)

        # big_square = Square(size=20, color=WHITE, fill_opacity = 1, fill_color=WHITE)
        # self.add(big_square)

        thanks_to_text = TextMobject('Thanks to:')
        
        uis_color = '#64bc3c'
        uis_logo = SVGMobject('UIS2', fill_opacity=0.4, fill_color=uis_color)
        uis_logo.scale(1)

        thanks_to_text.next_to(uis_logo, LEFT, buff=0.2)

        self.play(Write(thanks_to_text))
        self.play(Write(uis_logo))

        self.wait(1)

        sea_logo = ImageMobject('SEA')
        sea_text = TextMobject('SEA', ' Biblioteca')
        sea_text.scale(2)
        sea_text[0].set_color(uis_color)

        self.play(ApplyMethod(thanks_to_text.next_to, sea_text, LEFT, buff=0.2))
        self.play(Transform(uis_logo, sea_text))

        self.wait(1)

        self.play(FadeOut(thanks_to_text), FadeOut(uis_logo))

        self.wait(1)

def main():
    os.system(r"manim Intro.py Intro -pl")

if __name__ == "__main__":
    main() 