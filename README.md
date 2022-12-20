## Implementation of dynamic bitsets using fixed width integer arrays

```cpp
	// initializing bit_array of size 20:
	bitstring b = bitstring(20);

	// setting 4th and 5th  bit to true:
	b.set(4, true);
	// b.set(4) also valid
	b.set(3);

	// viewing the entire bitstring:
	b.show();

	// toggling the 4th bit
	b.toggle(3);

	// accessing the 4th and 5th bit:
	cout << "Bit 4 : " << b[3] << ", Bit 5 : " << b[4];
	// b.get(4) also valid

	// resetting the bitstring:
	b.reset();
```

## Reference:

### This legendary [stackoverflow answer](https://stackoverflow.com/questions/47981/how-do-i-set-clear-and-toggle-a-single-bit)
