void setup() {
  Serial.begin(115200);

  uint32_t limit{4000000};
  uint32_t current[2] {0, 1};
  uint32_t next{0};

  long unsigned sum{0};

  Serial.printf("\n\nsum of all fibonacci numbers < %i\n\n", limit);

  while (current[0] + current[1] < limit) {
    next = current[0] + current[1];
    sum += !(next & 1) ? next : 0;
    current[0] = current[1];
    current[1] = next;
    Serial.printf("%i %s\n", next, !(next & 1) ? "even" : "");
  }
  Serial.printf("\nsum of all even fibonacci numbers < %i = %lu\n",limit, sum);
}

void loop() {
  delay(1000);
}
