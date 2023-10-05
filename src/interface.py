class Exchange:
    # implement this!

    balance = 0

    def __init__(self, initialBalance):
        """Initial Balance is the amount that each account should start with."""
        self.balance = initialBalance

    # Let's suppose that trade has three parameters buy/sell, quantity, and price
    def add_trade(self, trade):
        """Adds a trade to the exchange (validation required)
        and returns a match if required. It is up to you on how you will
        handle representing trades. """

        if trade.buy:
            balance -= trade.quantity * trade.price
        else:
            balance += trade.quantity * trade.price

        raise NotImplementedError

