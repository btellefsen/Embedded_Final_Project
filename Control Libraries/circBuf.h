/*
 * circbuf.h
 *
 *  Created on: Oct 11, 2016
 *      Author: Cameron Handeland
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef CIRCBUF_H_
#define CIRCBUF_H_



typedef struct CircBuf_t{
 	volatile int8_t * head; // Pointer to first item
 	volatile int8_t * tail; // Pointer to last item

 	volatile uint32_t num_items; // Number of items in buffer
 	volatile uint32_t length;// Max number of items the buffer can hold
 	int8_t * buffer; // Pointer to beginning of buffer in heap
 } CircBuf;

 void initializeBuffer(CircBuf * buf, uint32_t length);
 void clearBuffer(CircBuf * buf);
 void deleteBuffer(CircBuf * buf);
 int8_t BufferFull(CircBuf * buf);
 int8_t BufferEmpty(CircBuf * buf);
 void addItemToBuffer(CircBuf * buf, volatile int8_t item);
 int8_t removeItemFromBuffer(CircBuf * buf, int8_t* item);

 void initializeBuffer(CircBuf * buf, uint32_t length){
 	 buf->buffer = malloc(sizeof(int8_t) * length); //Points to beginner of buffer
 	 if(buf == NULL | buf->buffer == NULL)
 		 return;
 	 buf->length = length;
 	 buf->head = buf->buffer;
 	 buf->tail = buf->buffer;
 	 buf->num_items = 0;
 	 return;
  }
 void clearBuffer(CircBuf * buf){
	 int8_t* temp;
	 while(BufferEmpty(buf) != 0){
		 removeItemFromBuffer(buf, temp);
	 }
 }
 void deleteBuffer(CircBuf * buf){
	 free(buf);
 }
 int8_t BufferFull(CircBuf * buf){
	 return buf->num_items == buf->length;
 }
 int8_t BufferEmpty(CircBuf * buf){
	 return buf->num_items == 0;
 }
 void addItemToBuffer(CircBuf * buf, volatile int8_t item){
	*buf->tail = item;

	 if(buf->tail+1 == (buf->buffer + buf->length))
		 buf->tail = buf->buffer;
	 else buf->tail++;
	 if(buf->num_items < 60){
	buf->num_items++;
	 }
 }
int8_t removeItemFromBuffer(CircBuf * buf, int8_t* item){

	if(buf == NULL | buf->buffer == NULL)
			 return -1;
	*item = *buf->head;

	if(buf->head+1==(buf->buffer + buf->length))
		buf->head = buf->buffer;
	buf->head++;
	if(buf->num_items > 0)
		buf->num_items--;
	return 0;
 }
#endif /* CIRCBUF_H_ */
