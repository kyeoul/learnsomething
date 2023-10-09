from interface import Exchange
from trade import Trade

if __name__ == "__main__":

    exchange = Exchange(100)

    trade1 = Trade(True, 10, 5.0)

    exchange.add_trade(trade1)

    print(exchange.balance)
    print(exchange.holding)

    trade2 = Trade(False, 10, 5.5)

    exchange.add_trade(trade2)

    print(exchange.balance)
    print(exchange.holding)

    trade3 = Trade(True, 10, 3.0)

    exchange.add_trade(trade3)

    print(exchange.balance)
    print(exchange.holding)