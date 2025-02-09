import aiogram, os, asyncio
from aiogram import *
from aiogram.types import Message
from aiogram.filters import CommandStart

TOKEN ="7747265900:AAGW-tRZNz_Di8_efuf_Ren1wqdHf02rnv4"

dp = Dispatcher(Bot)

@dp.message(CommandStart())
async def mess(message: Message):
    await message.answer("Star")

async def main():
    bot = Bot(token = TOKEN)
    await dp.start_polling(bot)

asyncio.run(main())


