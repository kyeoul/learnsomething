class Exchange:
    # implement this!

    balance = 0
    trades = []
    holding = 0

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.balance = initialBalance

    # Let's suppose that trade has three parameters buy/sell, quantity, and price
    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """
        self.trades.append(trade)
        money = trade.quantity * trade.price

        if trade.buy:
            if money > self.balance:
                print("youre too poor lmao")
            else:
                self.balance -= money
                self.holding += trade.quantity
        else:
            if self.holding < trade.quantity:
                print("you dont have enough stonks")
            else:
                self.balance += money
                self.holding -= trade.quantity

            
