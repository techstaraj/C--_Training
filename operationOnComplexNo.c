// Write a program that use function to perform the operation.
// 1. Reading a complex number.
// 2. Writing a complex number.
// 3. Addition of complex number.
// 4. Multiplication of complex number.

#include <stdio.h>

struct complex
{
  float real;
  float img;
};

void readComplex(struct complex *num)
{
  printf("Enter real part : ");
  scanf("%f", &num->real);
  printf("Enter imaginary part : ");
  scanf("%f", &num->img);
}

void writeComplex(struct complex num)
{
  printf("%.2f + i%.2f\n", num.real, num.img);
}

struct complex addComplex(struct complex num1, struct complex num2)
{
  struct complex result = {num1.real + num2.real, num1.img + num2.img};
  return  result;
}

struct complex multiComplex(struct complex num1, struct complex num2)
{
  struct complex product = {((num1.real * num2.real) - (num1.img * num2.img)), ((num1.real * num2.img) + (num1.img * num2.real))};
  return product;
}

int main()
{
  struct complex num1, num2;

  // Reading Complex Numbers from user
  printf("For First Number :- \n");
  readComplex(&num1);
  printf("For Second Number :- \n");
  readComplex(&num2);

  // Writing Complex Numbers
  printf("Frist Number : ");
  writeComplex(num1);
  printf("Second Number : ");
  writeComplex(num2);

  // Adding Two Complex Numbers
  struct complex add = addComplex(num1, num2);
  printf("Addition : ");
  writeComplex(add);

  // Multiply Two Complex Numbers
  struct complex multiply = multiComplex(num1, num2);
  printf("Multiplication : ");
  writeComplex(multiply);

  return 0;
}
