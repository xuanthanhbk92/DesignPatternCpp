# Creation design pattern
Dung de quan ly cach thuc khoi tao doi tuong . Giai quyet cac van de ve khoi tao doi tuong



## Singleton
Mot class ma chi cho phep ton tai duy nhat mot doi tuong
Problem: can duy nhat 1 instance cho 1 app
--- Dung khi ca app chi can mot doi tuong duy nhat
--- Han che viec tao ra nhieu doi hon 1 doi tuong cua class nay

## Abstract Factory
Tao mot instance cua mot vai family class
Problem : Khi muon app portable cho nhieu platform. Chung ta phai dung nhieu ifdef. Lam sao de giai quyet
--- Cung cap 1 interface de tao ra mot gia dinh cac doi tuong lien quan hoac phu thuoc maf khong neu ro cac lop cu the cua chung
--- Cung cap mot nha may phan cap dong goi : nhieu platforms phu hop, su tao ra cua mot bo san pham
--- Toan tu New duoc coi la co hai
Cach su dung :
## Builder
Separate object construction from its representation

Phan tich mot doi tuong phuc tap thanh nhieu phan va mot quy trinh xay dung
Moi quy trinh xay dung khac nhau se tac ra 1 muc tieu khac nhau
Class dung builder se xay dung doi tuong tung phan 1

## Factory Method
Creates an instance of several derived classes

## Object Pool
Tranh viec thu hoi va giai phong tai nguyen bang cach tai su dung nhung tai nguyen khong con su dung

## Prototype
Mot doi tuong khoi tao hoan chinh de copy hoac clone







