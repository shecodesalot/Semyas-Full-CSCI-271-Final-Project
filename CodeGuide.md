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

## Card Balance Feature

### Overview

The simulator now includes a card balance that goes down with each approved purchase. The balance is tracked in the background and is not shown to the user.

### Starting Balance

The card starts with **$30.00**, stored as a `double` named `cardBalance` in `main()`:

```cpp
double cardBalance = 30.00;
```

It is not `const` because it changes as items are bought.

### How It Works

1. The user chooses an item and enters the card PIN.
2. If the balance is lower than the item price, the purchase is declined with an "insufficient funds" message and stock is not changed.
3. If the balance is enough, the price is subtracted from `cardBalance`, stock goes down by one, and the item is dispensed.

The balance is never printed. Users only see whether a purchase was approved or declined.

### Why the Balance Is Hidden

A real vending machine doesn't show a card's balance. Customers check it in their banking app or with their card provider. The simulator follows the same approach.

### Rounding

Doubles can't store some decimal values exactly, so small rounding errors can build up over many subtractions. In this program, the balance is only reduced a few times, so the error stays far below one cent and is very unlikely to matter. The one edge case is spending down to exactly $0.00, where a tiny leftover amount could decline a purchase that should succeed. Storing values in integer cents (such as `3000` for `$30.00`) avoids this completely.

## How to Run

Compile and run with any C++11 or newer compiler:

```bash
g++ -std=c++11 -o vending vending.cpp
./vending
```

On Windows with MinGW, use `g++ -std=c++11 -o vending.exe vending.cpp` and then run `vending.exe`.

If using OnlineGDB: paste the whole .cpp program into the editor, make sure the language is set to C++, then click Run. The PIN is 4821, and you'll see the card-only notice when the program starts.

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