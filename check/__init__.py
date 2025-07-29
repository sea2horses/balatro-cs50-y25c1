import check50
import check50.c

@check50.check()
def exists():
    """balatro.c exists"""
    check50.exists("balatro.c")

@check50.check(exists)
def compiles():
    """balatro.c compiles"""
    check50.c.compile("balatro.c", lcs50=True)

@check50.check(compiles)
def royal_flush():
    """Handles Royal Flush"""
    check50.run("./balatro").stdin("AH").stdin("KH").stdin("QH").stdin("JH").stdin("TH").stdout("Points for play: 10000").exit(0)

@check50.check(compiles)
def four_of_a_kind():
    """Handles Four of a Kind"""
    check50.run("./balatro").stdin("8S").stdin("8H").stdin("8D").stdin("8C").stdin("2H").stdout("Points for play: 3000").exit(0)

@check50.check(compiles)
def full_house():
    """Handles Full House"""
    check50.run("./balatro").stdin("9S").stdin("9H").stdin("9C").stdin("6D").stdin("6S").stdout("Points for play: 2000").exit(0)

@check50.check(compiles)
def low_straight():
    """Handles Low Straight (A-2-3-4-5)"""
    check50.run("./balatro").stdin("2D").stdin("3C").stdin("4S").stdin("5H").stdin("AH").stdout("Points for play: 1000").exit(0)

@check50.check(compiles)
def mixed_case_input():
    """Handles mixed case input"""
    check50.run("./balatro").stdin("ah").stdin("kh").stdin("qh").stdin("jh").stdin("th").stdout("Points for play: 10000").exit(0)

@check50.check(compiles)
def invalid_card_length():
    """Handles invalid card length"""
    check50.run("./balatro") \
        .stdin("QH").stdin("KD").stdin("Z").stdout("Card #3").stdin("9C").stdin("TH").stdin("4H") \
        .stdout("Points for play: 50").exit(0)

@check50.check(compiles)
def invalid_value_letter():
    """Handles invalid value letter"""
    check50.run("./balatro") \
        .stdin("QH").stdin("KD").stdin("ZC").stdout("Card #3").stdin("9C").stdin("TH").stdin("4H") \
        .stdout("Points for play: 50").exit(0)

@check50.check(compiles)
def invalid_suit():
    """Handles invalid suit"""
    check50.run("./balatro") \
        .stdin("QH").stdin("KD").stdin("9X").stdout("Card #3").stdin("9C").stdin("TH").stdin("4H") \
        .stdout("Points for play: 50").exit(0)

@check50.check(compiles)
def duplicate_cards():
    """Handles duplicate cards"""
    check50.run("./balatro") \
        .stdin("QH").stdin("QH").stdout("Card #2").stdin("9D").stdin("3C").stdin("TH").stdin("4H") \
        .stdout("Points for play: 50").exit(0)