# Vending Machine (C++)

A console vending machine simulator for C++ assignment. It lists four products with prices and stock, accepts card payment only, and checks a preset PIN before dispensing.

## Features

- **Card payment only.** The machine shows "CARD PAYMENT ONLY" on screen and states that cash is not accepted.
- **Preset PIN.** A card PIN is checked before each sale. The remaining attempts are shown before every PIN prompt, and the customer gets 3 tries.
- **Stock tracking.** Each product starts with 5 units. The machine shows `xN` for stock on hand and `SOLD OUT` at 0.
- **Safe input.** Invalid numbers are rejected and the user is asked again.

## Products

| # | Product | Price | Starting stock |
|---|---------|-------|----------------|
| 1 | Diet Coke | $2.50 | 5 |
| 2 | KitKat Bar | $1.50 | 5 |
| 3 | Kinder Bueno 2 Pack | $2.35 | 5 |
| 4 | 1 Pack Lrg Soft Chocolate Chip Cookie | $2.90 | 5 |

## Demo Card PIN

The demo card PIN is **4821**. It is set in the code as `CARD_PIN`. This is a demo value for coursework only, not a real payment credential.

## How to Run

Compile and run with any C++11 or newer compiler:

```bash
g++ -std=c++11 -o vending vending.cpp
./vending
```

On Windows with MinGW, use `g++ -std=c++11 -o vending.exe vending.cpp` and then run `vending.exe`.

## How to Use

1. Choose `1` from the main menu to buy an item.
2. Pick an item number from the machine, or enter `0` to cancel.
3. The machine shows the price and the attempts remaining, then asks for the card PIN.
4. If the PIN is correct, the item is dispensed and its stock goes down by one.
5. If the PIN fails 3 times, the card is declined and the stock stays the same.
6. Choose `0` from the main menu to exit.

## Code Structure

- `CARD_PIN` and `MAX_PIN_TRIES`: the preset PIN and the number of allowed attempts.
- `Item` struct: holds `name`, `price`, and `stock` for each product.
- `printMachine()`: draws the machine, its stock, and the card-only notice.
- `readInt()`: reads a whole number and rejects bad input.
- `checkCardPin()`: shows the attempts remaining and checks the PIN.
- `buyItem()`: runs the purchase. It uses an `Item&` reference so stock changes update the vector.
- `main()`: holds the product list and the menu loop.

## Author

Semya, with the help of Viro AI in brainstorming and formatting!