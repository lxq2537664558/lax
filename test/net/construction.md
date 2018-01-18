# construction - net 

 roughly in the order of implementation: 

 - unique int32 id over time 
   - big stride... 
   - ?

 - read buffer 
   - get a block of memory from a pool of diverse size 
   - 2^N sized blocks 
   - resize gets memory from the pool 
   - return buffer to OS with configured parameters


 - write buffer
   - current buffer implementation seems fine 
   - equall sized blocks 

 - protocol 
   - handle serialization and deserialization 
   - handle encryption and decryption 
   - handle key exchange and setup 

 - msgpack : protocol 

 - session 
 - service 
 - acceptor 
 - connector integration 

 - send 
   - ref
   - remove direct access to session especially with service::get() for performance

 - logging 
   - enable / disable for network (global option)    

 - unit tests 

 - samples 
   - performance test 
   - encryption test 


## buffer 

 - send_buffer 
 - recv_buffer 

 memcpy�� ���� ���� ȣ���� �� ������ ����ȭ�� �ߴ�. 
 check() ��ũ�� ������ ������ Shipping ���带 �߰��ؾ� �Ѵ�. 



## Serialization 

msgpack���� ������ �����̾����� �������� ���� ������. ���� ��� �ʴ� �鸸�� �̻��� �����ϳ� 
���鸸 ���� ��ǥ�� �ϰ� �־� �ٸ� ���̺귯���� �߰��� ã�� �׽�Ʈ �ߴ�. 

- flatbuffers 
  - ����� �� �����ϴ�. 
  - ���� ������ �����ϸ� msgpack���ٴ� �������� ���� �������� �ʴ�. 
  - ���� �� �������� ���� lax�� ���� ���ʿ��ϴ�. 
- yas 
  - ����ϳ� �ӵ��� flatbuffers �����̴�. 
  - �ణ �� ���� ���� 
  - ����� �������� ���� shared_buffer�� ��ü�� �������̽��� ���� 
- bitsery 
  - ��Ʈ��ũ�� serialization ���̺귯���� ���� �Ǿ��� 
  - �ڵ��� ��Ʈ��ó�� �״�� �޼����� ����ϴ� ����. ������ ���� �������� �����̴�. 
  - �ӵ��� msgpack���� �� �� ���� ������. 
  - buffer�� ���� ������ �� �־� �߰� �޸� �Ҵ� / ������ ����. 

���� ���� ������ bitsery�� ����ϱ�� �ߴ�. �ڵ� ǰ���� ������ ������ ���δ�. 
���� ������ ���� �ʾ� ���س� ������� ������� ���� �� �ϴ�. 
clang�� �����ϴ� �ȵ���̵峪 iOS ���嵵 ū �̽��� ���� �� �ϴ�. 

### bits_protocol 

bitsery�� ����ϴ� ��������. bitsery�� ���þƾ�� ���� �����̶� ���ε� 
�ͼ����� �����Ƿ� bits�� �θ���. 

bits_message, bits_factory, bits_protocol�� �ʿ�. ���� �����ϱ� ���� 
������ ���� �׽�Ʈ�� �����ϸ鼭 �����Ѵ�. 

## service / protocol / session / acceptor / connector 

�ѹ��� �����ؾ� �Ѵ�. ��ȣ ������ �����ϴ�. 
�۾��� �� ������ ���´�. 

## protocol


## bits 


## session 

ä�ΰ� ref ����� session�� service�� �̵�. 
�ͼ��� session �������� �����ϰ� 
���������� factory�� ó����. 
�������� ��Ī�� �ָ� �ش� ���������� ã�Ƽ� �����ϵ��� ��


### channel 

### ref 

close�� ���� �ݹ� ó���� ���� ���� �ϱ� ���ٴ� 
close �޼����� ���� ���� ���̵�� üũ�ؼ� �����ϵ��� �Ѵ�. 
Ư���� subscription�� �����ϵ��� �Ѵ�. 
������ ���� �ʿ��ϴ�. id�� ã�Ƽ� �ش� id�� ��ϵ� �͵鿡 �뺸�Ѵ�. 

�̷��� �ϴ� �� ���� ���δ�. 


## service 

 acceptor / connector only. 

 protocol_msgpack::sub()�� ���ؼ� ����

 protocol::ref�� ���� ����


### slot 

### acceptor 

### connector 


## server


### binder / holder 


## actor 


## interface 

 auto& svc = net::service::inst(); 

 session::sub( topic(bits, new_session), on_new_bits_session );

 svc.accept( ..., "bits");
 svc.connect( ..., "bits"); 

 on_new_session(m) 
 {
	// ���μ��� 	
	auto sref = net::service::inst().acquire(m->id())
	
	sref.send( nm );
	
	sref.close();
 } 

 - ����� 
 - ���� ����  
 - ���� ����  

 ��ü������ ����ϴ�. 

 heartbeat ���� ��? 

 - �شܿ� �� �ʿ� ���� send() �� �� (����� ��) Ȯ���ϰ� ���� ��Ŵ
 - ������ �ϵ��� �� 


