// ================= BUCKET ARRAY =================
// Bucket Array is an array where each index (bucket)
// stores data having the same hash value.\
//Its visualisation are like:
// index-> key elem -> value


// ================= HASH CODE =================
// Hash Code is an integer generated from a key.
// It is used to decide where the value should be stored.
// Example:
// Key = "abc"
// Hash Code = 96354

// ================= COMPRESSION FUNCTION =================
// Converts a large hash code into a valid bucket index.

// Formula:
// bucketIndex = hashCode % bucketSize
//
// Example:
// hashCode = 96354
// bucketSize = 10
// bucketIndex = 4

// ================= COLLISION =================
// Collision occurs when two different keys
// get mapped to the same bucket index.
//
// Example:
// hash("abc") % 10 = 4
// hash("xyz") % 10 = 4
//
// Collision Handling:
// 1. Separate Chaining
// 2. Open Addressing (Linear, Quadratic, Double Hashing)
