/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 * Copyright 2023 Manuel Jedinger
 * https://github.com/manujedi
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include <stdint.h>
#include <string.h>

extern uint32_t __bss_start__[];
extern uint32_t __bss_end__[];
extern uint8_t flash_data_start[];
extern uint8_t sram_data_start[];
extern uint8_t sram_data_end[];

void BSS_Init(void);
void DATA_Init(void);

void BSS_Init(void)
{
    memset(__bss_start__, 0, (size_t)((uint8_t *)__bss_end__ - (uint8_t *)__bss_start__));
}

void DATA_Init(void)
{
    memcpy(sram_data_start, flash_data_start, (size_t)(sram_data_end - sram_data_start));
}
