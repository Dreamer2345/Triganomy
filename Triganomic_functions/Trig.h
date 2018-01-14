#pragma once

using AngleResult = SFixed<1, 14>;

const AngleResult PROGMEM AngleTable[64] = {0.0, 0.0245, 0.0491, 0.0736, 0.098, 0.1224, 0.1467, 0.171, 0.1951, 0.2191, 0.243, 0.2667, 0.2903, 0.3137, 0.3369, 0.3599, 0.3827, 0.4052, 0.4276, 0.4496, 0.4714, 0.4929, 0.5141, 0.535, 0.5556, 0.5758, 0.5957, 0.6152, 0.6344, 0.6532, 0.6716, 0.6895, 0.7071, 0.7242, 0.741, 0.7572, 0.773, 0.7883, 0.8032, 0.8176, 0.8315, 0.8449, 0.8577, 0.8701, 0.8819, 0.8932, 0.904, 0.9142, 0.9239, 0.933, 0.9415, 0.9495, 0.9569, 0.9638, 0.97, 0.9757, 0.9808, 0.9853, 0.9892, 0.9925, 0.9952, 0.9973, 0.9988, 0.9997};

AngleResult AngleLookup(uint_fast8_t index)
{
    AngleResult k = 0;
    memcpy_P(&k,&AngleTable[(index & (0x3F))],2);
    return (index == 64) ? 1 : k;
}

AngleResult Sin(uint8_t brads)
{
  const uint8_t quarter = ((brads & 0xC0) >> 6);
  const uint8_t index = ((brads & 0x3F) >> 0);
  switch (quarter)
  {
  case 0: return AngleLookup(index);
  case 1: return AngleLookup(64 - index);
  case 2: return -AngleLookup(index);
  case 3: return -AngleLookup(64 - index);
  default: return 0;
  }
}

AngleResult Cos(uint8_t brads)
{
  const uint8_t quarter = ((brads & 0xC0) >> 6);
  const uint8_t index = ((brads & 0x3F) >> 0);
  switch (quarter)
  {
  case 0: return AngleLookup(64 - index);
  case 1: return -AngleLookup(index);
  case 2: return -AngleLookup(64 - index);
  case 3: return AngleLookup(index);
  default: return 0;
  }
}





