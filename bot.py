import aiogram, os, asyncio
from aiogram import Bot, Dispatcher
from aiogram.types import Message
from aiogram.filters import CommandStart, Command


TOKEN ="7747265900:AAGW-tRZNz_Di8_efuf_Ren1wqdHf02rnv4"

dp = Dispatcher()

@dp.message(CommandStart())
async def start(message: Message):
    await message.answer("Star")

@dp.message(Command("help"))
async def help(message: Message):
    await message.answer("Do you need any help?")

async def main():
    bot = Bot(token = TOKEN)
    await dp.start_polling(bot)

asyncio.run(main())


