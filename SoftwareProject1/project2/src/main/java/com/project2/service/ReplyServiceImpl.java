package com.project2.service;

import java.util.List;

import javax.inject.Inject;

import org.springframework.stereotype.Service;

import com.project2.dao.ReplyDAO;
import com.project2.domain.ReplyVO;

@Service // create this class to bean object of root container
public class ReplyServiceImpl implements ReplyService {
	@Inject // find bean object for same name
	ReplyDAO dao; // declare ReplyDAO object

	@Override
	public List<ReplyVO> readReply(int bno) throws Exception {
		// TODO Auto-generated method stub
		return dao.readReply(bno); // call readReply
	}

	@Override
	public int countReply(int bno) throws Exception {
		// TODO Auto-generated method stub
		return dao.countReply(bno); // call countReply
	}

	@Override
	public void writeReply(ReplyVO vo) throws Exception {
		// TODO Auto-generated method stub
		dao.writeReply(vo); // call writeReply
	}

	@Override
	public ReplyVO viewReply(int rno) throws Exception {
		// TODO Auto-generated method stub
		return dao.viewReply(rno); // call viewReply
	}

	@Override
	public void deleteReply(int rno) throws Exception {
		// TODO Auto-generated method stub
		dao.deleteReply(rno); // call deleteReply
	}

}
